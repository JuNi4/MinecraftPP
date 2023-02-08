#include "keyCodes.hpp"

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