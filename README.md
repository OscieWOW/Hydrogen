# Hydrogen
>[!NOTE] 
>Hydrogen is still in developement and will not be completed for a while.

>[!IMPORTANT]
>Everything is subject to change so the listed features may not always be a representation of the actual implemented code. 


## Logger ##
The logging system is first initialised in the entry point function.
```cpp
void Log::logInit() {
	clientLogger.setLogFormat("[%N %T] %M");
	hydrogenLogger.setLogFormat("[%N %T] %M");
}
```
This sets the format of the log messages to first contain the name of the logger, then the time and finaly the message.
The loggers also have macros defined in the `Log` class as:
```cpp
#define H_CORE_TRACE(...)  Hydrogen::Log::hydrogenLogger.logTrace(__VA_ARGS__)
#define H_CORE_MESSAGE(...)  Hydrogen::Log::hydrogenLogger.logMessage(__VA_ARGS__)
#define H_CORE_WARN(...)  Hydrogen::Log::hydrogenLogger.logWarning(__VA_ARGS__)
#define H_CORE_FATAL(...)  Hydrogen::Log::hydrogenLogger.logFatal(__VA_ARGS__)

#define H_TRACE(...)  Hydrogen::Log::clientLogger.logTrace(__VA_ARGS__)
#define H_MESSAGE(...)  Hydrogen::Log::clientLogger.logMessage(__VA_ARGS__)
#define H_WARN(...)  Hydrogen::Log::clientLogger.logWarning(__VA_ARGS__)
#define H_FATAL(...)  Hydrogen::Log::clientLogger.logFatal(__VA_ARGS__)
```
If a message is sent via trace:
```cpp
H_CORE_TRACE("core trace example");
```

Then the message is displayed according to the specified format:
>[HYDROGEN 13:01:12] core example trace

## Layers ##
The application class specifies `m_layerStack` which is where all layers are stored after they are added to the app. All events are prpogated through the layer stack which will call each layers onEvent function.
Layers require `layerData` to be passed to the constructor, this will include an onEvent function for individual layers to generate events to be passed through the app aswell as a debug name for the layer's logger.

## Events ##
Events are passed by the apps onEvent function. Within the function an event dispatcher is made which will compare the generated event to a pre-specified type to then determine if the bound callback function should be run. If the app has no callback for the event then it will be propogated through the layer stack for the layers to handle events in the same way with an event dispatcher.
``` cpp
void Application::onEvent(Event& e) {
	Hydrogen::Scope<EventDispatcher> dispatcher = Hydrogen::createScope<EventDispatcher>(e);

	H_CORE_MESSAGE(e.traceEvent());

	//App Events
	dispatcher->dispatch<AppUpdate>(BIND_EVENT_FUNCTION(onAppUpdate));
	dispatcher->dispatch<AppRender>(BIND_EVENT_FUNCTION(onAppRender));

	//Window Events
	dispatcher->dispatch<WindowClose>(BIND_EVENT_FUNCTION(onWindowClose));

	m_layerStack.onEvent(e);
}
```
All inputs are passed via either a `KeyEvent` or a `MouseEvent` this then abstracts any platform specific code from the rest of the code.

## Graphics ## 
Graphics are split into seperate APIs for the different graphics APIs. Currently OpenGL is being implemented however, in the future Vulkan is planned to be implemented.
For use in the application the graphics code is placed into the render engine which handles calls to shaders and to the render API.

## Engines ##
Hydrogen includes an engine system which is used to simplify code into individual functions for use in the app.

## Entity and scene systems ## 
Entity and scene systems are also a future planned feature. This would allow games to be made easily and with minimal extra set up, all that would be required would be a scene and entities to add to the scene.
