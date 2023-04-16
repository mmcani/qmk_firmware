//
// Created by can on 16.04.23.
//
#pragma once

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 1000

#ifdef DEBOUNCE
#undef DEBOUNCE
#endif
#define DEBOUNCE 3

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 90
#define TAPPING_TERM_PER_KEY