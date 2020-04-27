#ifndef TEXTURE_CREATESHADERMODULE_H
#define TEXTURE_CREATESHADERMODULE_H

#include <vulkan_wrapper.h>
#include <android_native_app_glue.h>
/*
 * buildShaderFromFile()
 *   Create a Vulkan shader module from the given glsl shader file
 *   Input shader is compiled with shaderc (https://github.com/google/shaderc)
 *   prebuilt binary on github (https://github.com/ggfan/shaderc/release)
 *
 *   The pre-built shaderc lib is packed as CDep format of:
 *      https://github.com/google/cdep
 *   Refer to full documentation from the above homepage
 *
 *   feedback for CDep is very welcome to the https://github.com/google/cdep
 * Input:
 *     appInfo:   android_app, from which get AAssertManager*
 *     filePaht:  shader file full name with path inside APK/assets
 *     type:      borrowed VK's shader type to indicate which glsl shader it is
 *     vkDevice:  Vulkan logical device
 * Output:
 *     shaderOut:  built shader module return to caller
 * Return:
 *     VK_SUCCESS: shader module is at shaderOut
 *     Others:  error happened, no shader module created at all
 */

VkResult buildShaderFromFile(
    android_app* appInfo,
    const char* filePath,
    VkShaderStageFlagBits type,
    VkDevice vkDevice,
    VkShaderModule* shaderOut);

#endif // TUTORIAL06_TEXTURE_CREATESHADERMODULE_H
