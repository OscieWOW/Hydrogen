# Hydrogen
>[!NOTE] 
>Hydrogen is still in developement and will not be completed for a while.

>[!IMPORTANT]
>Everything is subject to change so the listed features may not always be a representation of the actual implemented code. 

# What is planned for the future? #

## Logger ##
A logging system is being worked on

## Layers and Events ##
Hydrogen will include an `Event` and `Layer` system. 
The `Event` will allow many things, but one main aspect of them is that inputs to be abstracted from the engine amd the actual application.
Layers will allow different aspects of the game to handle an event or allow it to propogate to the other layers. 

## Graphics ## 
A graphics rendering API is planned for the future.
The API would mean that the link between the hydrogen draw and other graphics related functions are abstracted.
This means that multiple graphics renderers can be used seamlessly and that new renderers can be added without having to rewrite the entire or even parts of the graphics engine
The following renderers are planned to be implemented:
- OpenGL
- Vulkan

With others being possibly added but the main focus will be on getting openGL working and the vulkan to prove the versatility of the graphics API

## Entity and scene systems ## 
Entity and scene systems are also a future planned feature. This would allow games to be made easily and with minimal extra set up, all that would be required would be a scene and entities to add to the scene.

## Input 
Input into the engine is planned to be partialy abstracted with `Events`.  These would be treated as the input. An input would be specified to throw an `Event` and so then when the event is passed to the corresponding layer it can be handeled as if that `Event` was itself the input.
