#pragma once

#include <gui/scene_manager.h>

// Generate scene id and total number
#define ADD_SCENE(prefix, name, id) LfRfidScene##id,
typedef enum {
#include "t5577_multiwriter_scene_config.h"
    LfRfidSceneNum,
} LfRfidScene;
#undef ADD_SCENE

extern const SceneManagerHandlers t5577_multiwriter_scene_handlers;

// Generate scene on_enter handlers declaration
#define ADD_SCENE(prefix, name, id) void prefix##_scene_##name##_on_enter(void*);
#include "t5577_multiwriter_scene_config.h"
#undef ADD_SCENE

// Generate scene on_event handlers declaration
#define ADD_SCENE(prefix, name, id) \
    bool prefix##_scene_##name##_on_event(void* context, SceneManagerEvent event);
#include "t5577_multiwriter_scene_config.h"
#undef ADD_SCENE

// Generate scene on_exit handlers declaration
#define ADD_SCENE(prefix, name, id) void prefix##_scene_##name##_on_exit(void* context);
#include "t5577_multiwriter_scene_config.h"
#undef ADD_SCENE
