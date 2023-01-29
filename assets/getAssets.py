import os,zipfile,platform,shutil,json,sys,getpass as gt, requests

PATH = os.path.abspath(os.path.dirname(__file__))

def getVersionMeta(version:str):
    """ Gets the json file storing information for the version

    `version` `string` The Minecraft version to get the textures from. Only used if the version is found localy

    `Returns` `dictionary` Returns the content of the meta file
    """
    # Get the latest version
    response = requests.get('https://piston-meta.mojang.com/mc/game/version_manifest_v2.json')
    version_list = json.loads(response.text)
    # Get the version selected
    version_id = -1
    if not version == 'latest':
        for i in range(len( version_list["versions"] )):
            if not version_list["versions"][i]["id"] == version: continue
            # When the correct version is found
            version_id = i
            break
    else:
        version_id = 0
    
    if version_id == -1:
        print('Did not find version: '+version)
        return {"error": "version not found"}

    print('Found version '+version+' ('+version_list["versions"][version_id]["id"]+')')

    #print(f'Found latest version: {version_list["versions"][0]["id"]}')
    print(f'Downloading...')
    # Download the latest version
    response = requests.get(version_list["versions"][0]["url"])
    version_data = json.loads(response.text)

    return version_data


def getAssets(version:str, force:bool=False):
    """ Gets the minecraft assets directly from mojang

    `version` `string` The Minecraft version to get the textures from. Only used if the version is found localy

    `force` `bool` If set to True, if the minecraft folder already exists, it will be replaced.

    `Returns` `bool` Wether or not it was succsesfull
    """

    # Check if the minecraft folder already exists
    if os.path.isdir(PATH+'/minecraft') and not force:
        return False
    
    elif os.path.isdir(PATH+'/minecraft') and force:
        shutil.rmtree(PATH+'/minecraft', ignore_errors=False, onerror=None)

    # Check if the minecraft version exists in
    # (On Linux) ~.minecraft/versions
    # (On Windows) %appdata%\.minecraft\versions
    if 'Windows' in platform.platform():
        VERSION_PATH = '%appdata%/.minecraft/versions'
    elif 'Linux' in platform.platform():
        VERSION_PATH = '/home/'+gt.getuser()+'/.minecraft/versions'
    else: return False # Any other operating system wont be supported (for now)

    # Path to the version.jar
    V_PATH = VERSION_PATH+'/'+version+'/'+version+'.jar'

    # Download the latest version from mojang
    if not os.path.isfile(V_PATH):
        V_PATH = PATH+'/client.jar'
        # Get Version Data
        version_data = getVersionMeta(version)
        # check if version was found
        if "error" in version_data: return False
        # Downaload Client
        response = requests.get(version_data["downloads"]["client"]["url"])
        with open(PATH+'/client.jar','wb') as c:
            c.write(response.content)

        print(f'Extracting...')


    try:
        # Open the version jar
        with zipfile.ZipFile(V_PATH) as versionFile:
            for f in versionFile.namelist():
                if f.startswith('assets/minecraft'):
                    # And extract everything from assets/minecraft
                    versionFile.extract(f, PATH)
                
        # Then move minecraft from assets/assets to assets/ and remove assets/assets
        shutil.move(PATH+'/assets/minecraft',PATH+'/minecraft')
        os.removedirs(PATH+'/assets')

        # Cleanup client.jar
        if os.path.isfile(PATH+'/client.jar'):
            os.remove(PATH+'/client.jar')

        return True
    except Exception as e: # Catch exceptions
        print(e)
        return False

def getResources(version:str, force:bool=False):
    """ Gets the resources from mojang

    `version` `string` the version to be used for getting the resources

    `force` `bool` if true, in case the resource folder already exists, it will be replaced

    `returns` `bool` wether or not the operation was succsessfull
    """
    RESOURCE_PATH = PATH + '/resources/'
    BASE_URL = "https://resources.download.minecraft.net/"

    # Check if RESOURCE_PATH exists
    if os.path.isdir(RESOURCE_PATH) and not force:
        return False
    
    elif os.path.isdir(RESOURCE_PATH) and force:
        shutil.rmtree(RESOURCE_PATH, ignore_errors=False, onerror=None)

    if not os.path.isdir(RESOURCE_PATH):
        os.mkdir(RESOURCE_PATH)


    versionData = getVersionMeta(version)

    if "error" in versionData: return False

    # Get the assets Index
    assetIndexURL = versionData["assetIndex"]["url"]
    response = requests.get(assetIndexURL)
    assetIndex = json.loads(response.text)["objects"]

    print('Downloading Resources...')

    # Download all assets
    for obj in assetIndex:
        # Get File Name Length
        file_name_length = len(obj.split('/')[-1])

        # Make all directorys for the file
        if not os.path.isdir(obj[:-file_name_length]):
            try:
                os.makedirs(RESOURCE_PATH+obj[:len(obj)-file_name_length-1])
            except:
                pass

        # Get the url to the file
        hash = assetIndex[obj]["hash"]
        block = hash[:2]

        url = BASE_URL+block+'/'+hash

        # Write the file
        with open(RESOURCE_PATH+obj, 'wb') as f:
            response = requests.get(url)
            f.write(response.content)

    return True

if '__main__' in __name__:
    # Get Args
    force = '-force' in sys.argv

    print('Getting assets:    '+str(getAssets('1.19.3',force)))
    print('Getting Resources: '+str(getResources('1.19.3', force)))