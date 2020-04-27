#include <android/log.h>
#include <android_native_app_glue.h>
#include <glm/glm.hpp>

#include "VulcanRenderer.h"

VulcanRenderer a;

// Process the next main command.
void handle_cmd(android_app* app, int32_t cmd) {
  switch (cmd) {
    case APP_CMD_INIT_WINDOW:
      // The window is being shown, get it ready.
      a.run(app);//Calls the ported pipeline that works on windows
      break;
    case APP_CMD_TERM_WINDOW:
      a.clean();
      break;
    default:
      __android_log_print(ANDROID_LOG_INFO, "Vulkan Tutorials",
                          "event not handled: %d", cmd);
  }
}

void android_main(struct android_app* app) {
  // Set the callback to process system events
  app->onAppCmd = handle_cmd;
  // Used to poll the events in the main loop
  int events;
  android_poll_source* source;

  // Main loop
  do {
      if (ALooper_pollAll(a.isVulcanReady ? 1 : 0, nullptr,
                          &events, (void**)&source) >= 0) {
          if (source != NULL) {
              source->process(app, source);
          }
      }
    if(a.isVulcanReady){a.render();}
  } while (app->destroyRequested == 0);
}
