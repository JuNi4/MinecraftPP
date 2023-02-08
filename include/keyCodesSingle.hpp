/**
 * @brief Convert LWJGE key codes to names as const char*
 * @author JuNi4
 * @date 2023/02/06 06.02.2023
*/

#ifndef _KEYCODES_H_
#define _KEYCODES_H_
#pragma once

/**
 * @brief A Class that holds information about all LWJGE Keys
 */
namespace LWJGEKeys {
        const int key_none = 0;
        const int key_escape = 1;
        const int key_1 = 2;
        const int key_2 = 3;
        const int key_3 = 4;
        const int key_4 = 5;
        const int key_5 = 6;
        const int key_6 = 7;
        const int key_7 = 8;
        const int key_8 = 9;
        const int key_9 = 10;
        const int key_0 = 11;
        const int key_minus = 12;
        const int key_equals = 13;
        const int key_back = 14;
        const int key_tab = 15;
        const int key_q = 16;
        const int key_w = 17;
        const int key_e = 18;
        const int key_r = 19;
        const int key_t = 20;
        const int key_y = 21;
        const int key_u = 22;
        const int key_i = 23;
        const int key_o = 24;
        const int key_p = 25;
        const int key_lbracket = 26;
        const int key_rbracket = 27;
        const int key_return = 28;
        const int key_lcontrol = 29;
        const int key_a = 30;
        const int key_s = 31;
        const int key_d = 32;
        const int key_f = 33;
        const int key_g = 34;
        const int key_h = 35;
        const int key_j = 36;
        const int key_k = 37;
        const int key_l = 38;
        const int key_semicolon = 39;
        const int key_apostrophe = 40;
        const int key_grave = 41;
        const int key_lshift = 42;
        const int key_backslash = 43;
        const int key_z = 44;
        const int key_x = 45;
        const int key_c = 46;
        const int key_v = 47;
        const int key_b = 48;
        const int key_n = 49;
        const int key_m = 50;
        const int key_comma = 51;
        const int key_period = 52;
        const int key_slash = 53;
        const int key_rshift = 54;
        const int key_multiply = 55;
        const int key_lmenu = 56;
        const int key_space = 57;
        const int key_capital = 58;
        const int key_f1 = 59;
        const int key_f2 = 60;
        const int key_f3 = 61;
        const int key_f4 = 62;
        const int key_f5 = 63;
        const int key_f6 = 64;
        const int key_f7 = 65;
        const int key_f8 = 66;
        const int key_f9 = 67;
        const int key_f10 = 68;
        const int key_numlock = 69;
        const int key_scroll = 70;
        const int key_n7 = 71;
        const int key_n8 = 72;
        const int key_n9 = 73;
        const int key_subtract = 74;
        const int key_n4 = 75;
        const int key_n5 = 76;
        const int key_n6 = 77;
        const int key_add = 78;
        const int key_n1 = 79;
        const int key_n2 = 80;
        const int key_n3 = 81;
        const int key_n0 = 82;
        const int key_decimal = 83;
        const int key_f11 = 87;
        const int key_f12 = 88;
        const int key_f13 = 100;
        const int key_f14 = 101;
        const int key_f15 = 102;
        const int key_f16 = 103;
        const int key_f17 = 104;
        const int key_f18 = 105;
        const int key_kana = 112;
        const int key_f19 = 113;
        const int key_convert = 121;
        const int key_noconvert = 123;
        const int key_yen = 125;
        const int key_nequals = 141;
        const int key_circumflex = 144;
        const int key_at = 145;
        const int key_colon = 146;
        const int key_underline = 147;
        const int key_kanji = 148;
        const int key_stop = 149;
        const int key_ax = 150;
        const int key_unlabeled = 151;
        const int key_nenter = 156;
        const int key_rcontrol = 157;
        const int key_section = 167;
        const int key_ncomma = 179;
        const int key_divide = 181;
        const int key_sysrq = 183;
        const int key_rmenu = 184;
        const int key_function = 196;
        const int key_pause = 197;
        const int key_home = 199;
        const int key_up = 200;
        const int key_prior = 201;
        const int key_left = 203;
        const int key_right = 205;
        const int key_end = 207;
        const int key_down = 208;
        const int key_next = 209;
        const int key_insert = 210;
        const int key_delete = 211;
        const int key_clear = 218;
        const int key_lmeta = 219;
        const int key_rmeta = 220;
        const int key_apps = 221;
        const int key_power = 222;
        const int key_sleep = 223;

        const int mouse_left = -100;
        const int mouse_right = -99;
        const int mouse_middle = -98;
        const int mouse_3 = -97;
        const int mouse_4 = -96;
        const int mouse_5 = -95;
        const int mouse_6 = -94;
        const int mouse_7 = -93;
        const int mouse_8 = -92;
        const int mouse_9 = -91;
        const int mouse_10 = -90;
        const int mouse_11 = -89;
        const int mouse_12 = -88;
        const int mouse_13 = -87;
        const int mouse_14 = -86;
        const int mouse_15 = -85;

//};
/**
 * @brief Convert any LWJGE key code to key names
 * 
 * @param keyCode The LWJGE key code to be converted
 * @return const char* the key name
 */
const char* convertKey(int keyCode) {
    // return the correct const char*
    switch (keyCode) {
    // Letters
    case LWJGEKeys::key_a: return "a";
    case LWJGEKeys::key_b: return "b";
    case LWJGEKeys::key_c: return "c";
    case LWJGEKeys::key_d: return "d";
    case LWJGEKeys::key_e: return "e";
    case LWJGEKeys::key_f: return "f";
    case LWJGEKeys::key_g: return "g";
    case LWJGEKeys::key_h: return "h";
    case LWJGEKeys::key_i: return "i";
    case LWJGEKeys::key_j: return "j";
    case LWJGEKeys::key_k: return "k";
    case LWJGEKeys::key_l: return "l";
    case LWJGEKeys::key_n: return "m";
    case LWJGEKeys::key_m: return "n";
    case LWJGEKeys::key_o: return "o";
    case LWJGEKeys::key_p: return "p";
    case LWJGEKeys::key_q: return "q";
    case LWJGEKeys::key_r: return "r";
    case LWJGEKeys::key_s: return "s";
    case LWJGEKeys::key_t: return "t";
    case LWJGEKeys::key_u: return "u";
    case LWJGEKeys::key_v: return "v";
    case LWJGEKeys::key_w: return "w";
    case LWJGEKeys::key_x: return "x";
    case LWJGEKeys::key_y: return "y";
    case LWJGEKeys::key_z: return "z";
    // Number row keys
    case LWJGEKeys::key_0: return "0";
    case LWJGEKeys::key_1: return "1";
    case LWJGEKeys::key_2: return "2";
    case LWJGEKeys::key_3: return "3";
    case LWJGEKeys::key_4: return "4";
    case LWJGEKeys::key_5: return "5";
    case LWJGEKeys::key_6: return "6";
    case LWJGEKeys::key_7: return "7";
    case LWJGEKeys::key_8: return "8";
    case LWJGEKeys::key_9: return "9";
    // F Keys
    case LWJGEKeys::key_f1: return "f1";
    case LWJGEKeys::key_f2: return "f2";
    case LWJGEKeys::key_f3: return "f3";
    case LWJGEKeys::key_f4: return "f4";
    case LWJGEKeys::key_f5: return "f5";
    case LWJGEKeys::key_f6: return "f6";
    case LWJGEKeys::key_f7: return "f7";
    case LWJGEKeys::key_f8: return "f8";
    case LWJGEKeys::key_f9: return "f9";
    case LWJGEKeys::key_f10: return "f10";
    case LWJGEKeys::key_f11: return "f11";
    case LWJGEKeys::key_f12: return "f12";
    case LWJGEKeys::key_f13: return "f13";
    case LWJGEKeys::key_f14: return "f14";
    case LWJGEKeys::key_f15: return "f15";
    case LWJGEKeys::key_f16: return "f16";
    case LWJGEKeys::key_f17: return "f17";
    case LWJGEKeys::key_f18: return "f18";
    case LWJGEKeys::key_f19: return "f19";
    // Arrow keys
    case LWJGEKeys::key_up: return "up";
    case LWJGEKeys::key_down: return "down";
    case LWJGEKeys::key_left: return "left";
    case LWJGEKeys::key_right: return "right";
    // Numpad Keys
    case LWJGEKeys::key_n0: return "n0";
    case LWJGEKeys::key_n1: return "n1";
    case LWJGEKeys::key_n2: return "n2";
    case LWJGEKeys::key_n3: return "n3";
    case LWJGEKeys::key_n4: return "n4";
    case LWJGEKeys::key_n5: return "n5";
    case LWJGEKeys::key_n6: return "n6";
    case LWJGEKeys::key_n7: return "n7";
    case LWJGEKeys::key_n8: return "n8";
    case LWJGEKeys::key_n9: return "n9";
    case LWJGEKeys::key_numlock: return "numlock";
    case LWJGEKeys::key_ncomma: return "ncomma";
    case LWJGEKeys::key_nenter: return "nenter";
    case LWJGEKeys::key_nequals: return "nequals";
    case LWJGEKeys::key_minus: return "-";
    case LWJGEKeys::key_multiply: return "*";
    case LWJGEKeys::key_add: return "+";
    case LWJGEKeys::key_divide: return "/";
    // other keys
    case LWJGEKeys::key_equals: return "=";
    case LWJGEKeys::key_comma: return ",";
    case LWJGEKeys::key_return: return "enter";
    case LWJGEKeys::key_escape: return "escape";
    case LWJGEKeys::key_lcontrol: return "lctrl";
    case LWJGEKeys::key_rcontrol: return "rctrl";
    case LWJGEKeys::key_lshift: return "lshift";
    case LWJGEKeys::key_rshift: return "rshift";
    case LWJGEKeys::key_back: return "back";
    case LWJGEKeys::key_semicolon: return ";";
    case LWJGEKeys::key_apostrophe: return "'";
    case LWJGEKeys::key_grave: return "grave";
    case LWJGEKeys::key_colon: return ",";
    case LWJGEKeys::key_lmenu: return "lmenu";
    case LWJGEKeys::key_rmenu: return "rmenu";
    case LWJGEKeys::key_decimal: return "decimal";
    case LWJGEKeys::key_scroll: return "scroll";
    case LWJGEKeys::key_space: return "space";
    case LWJGEKeys::key_capital: return "capital";
    case LWJGEKeys::key_backslash: return "backslash";
    case LWJGEKeys::key_slash: return "slash";
    case LWJGEKeys::key_power: return "power";
    case LWJGEKeys::key_lmeta: return "lwin";
    case LWJGEKeys::key_rmeta: return "rwin";
    // Mouse buttons
    case LWJGEKeys::mouse_left: return "lmb";
    case LWJGEKeys::mouse_right: return "rmb";
    case LWJGEKeys::mouse_middle: return "mmb";
    case LWJGEKeys::mouse_3: return "mb3";
    case LWJGEKeys::mouse_4: return "mb4";
    case LWJGEKeys::mouse_5: return "mb5";
    case LWJGEKeys::mouse_6: return "mb6";
    case LWJGEKeys::mouse_7: return "mb7";
    case LWJGEKeys::mouse_8: return "mb8";
    case LWJGEKeys::mouse_9: return "mb9";
    case LWJGEKeys::mouse_10: return "mb10";
    case LWJGEKeys::mouse_11: return "mb11";
    case LWJGEKeys::mouse_12: return "mb12";
    case LWJGEKeys::mouse_13: return "mb13";
    case LWJGEKeys::mouse_14: return "mb14";
    case LWJGEKeys::mouse_15: return "mb15";
    
    //case LWJGEKeys::key_: return "";
    //case LWJGEKeys::mouse_: return "";
    
    default: return "none";
    }
}

};

#endif