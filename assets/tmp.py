def getSounds(version='1.19',force=False):
    """ Copies audio files from indescript hashed folders to named sorted folders.

    `version` The Minecraft version to get the textures from. (General version, not the subversion number -> 1.19 not 1.19.3)

    `force` If set to True, if the minecraft folder already exists, it will be replaced.

    `Returns` `bool` Wether or not it was succsesfull
    """
    
    # Check if the sounds folder already exists
    if os.path.isdir(PATH+'/sounds') and not force:
        return False
    
    elif os.path.isdir(PATH+'/sounds') and force:
        shutil.rmtree(PATH+'/sounds', ignore_errors=False, onerror=None)

    # Get the path for the sound folder
    # (On Linux) ~.minecraft/assets
    # (On Windows) %appdata%\.minecraft\assets
    if 'Windows' in platform.platform():
        ASSETS_PATH = '%appdata%/.minecraft/assets'
    elif 'Linux' in platform.platform():
        ASSETS_PATH = '/home/'+gt.getuser()+'/.minecraft/assets'
    else: return False # Any other operating system wont be supported (for now)

    MC_OBJECT_INDEX = f"{ASSETS_PATH}/indexes/{version}.json"
    MC_OBJECTS_PATH = f"{ASSETS_PATH}/objects"
    MC_SOUNDS = r"minecraft/sounds/"
    OUTPUT_PATH = PATH+'/sounds'

    try:
        with open(MC_OBJECT_INDEX, "r") as read_file:
            # Parse the JSON file into a dictionary
            data = json.load(read_file)

            # Find each line with MC_SOUNDS prefix, remove the prefix and keep the rest of the path and the hash
            sounds = {k[len(MC_SOUNDS):] : v["hash"] for (k, v) in data["objects"].items() if k.startswith(MC_SOUNDS)}

            for fpath, fhash in sounds.items():
                # Ensure the paths are good to go for Windows with properly escaped backslashes in the string
                src_fpath = os.path.normpath(f"{MC_OBJECTS_PATH}/{fhash[:2]}/{fhash}")
                dest_fpath = os.path.normpath(f"{OUTPUT_PATH}/{fpath}")

                # Make any directories needed to put the output file into as Python expects
                os.makedirs(os.path.dirname(dest_fpath), exist_ok=True)

                # Copy the file
                shutil.copyfile(src_fpath, dest_fpath)

        return True
    except Exception as e: # Catch exceptions
        print(e)
        return False