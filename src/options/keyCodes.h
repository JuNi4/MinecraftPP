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
        /**
         * @brief Convert any LWJGE key code to key names
         * 
         * @param keyCode The LWJGE key code to be converted
         * @return const char* the key name
         */
        const char* convertKey(int keyCode);
};

#endif