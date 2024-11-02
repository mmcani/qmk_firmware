//
// Created by can on 08.04.23.
//
#pragma once

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// udef stuff we don't use, and limit sizes and stuff
#define DYNAMIC_KEYMAP_LAYER_COUNT 3

// special features
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 1000

// debounce settings
#define DEBOUNCE 3

// tap dance settings
#define TAPPING_TOGGLE 2
#define TAPPING_TERM 100
#define TAPPING_TERM_PER_KEY
