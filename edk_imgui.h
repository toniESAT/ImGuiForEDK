#pragma once

#include "imgui.h"
#include "imgui_internal.h"

#define GLFW_EXPOSE_NATIVE_WIN32
#include "backends/glfw/glfw3.h"
#include "backends/glfw/glfw3native.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

using namespace EDK3ImGui;

inline void ImGuiInit(float window_width, float window_height) {
  EDK3ImGui::ImGuiContext* ctx = ImGui::CreateContext();
  ImGui::SetCurrentContext(ctx);
  GLFWwindow* window = glfwGetCurrentContext();
  ImGuiIO& io = ImGui::GetIO();
  io.DisplaySize = ImVec2(window_width, window_height);
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");
}

inline void ImGuiNewFrame() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

inline void ImGuiDraw() {
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

inline void WindowMakeResizable() {
  GLFWwindow* window = glfwGetCurrentContext();
  HWND hwnd = glfwGetWin32Window(window);
  LONG_PTR style = GetWindowLongPtr(hwnd, GWL_STYLE);
  style |= WS_SIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME;
  SetWindowLongPtr(hwnd, GWL_STYLE, style);
}

inline void WindowMakeBorderless() {
  GLFWwindow* window = glfwGetCurrentContext();
  HWND hwnd = glfwGetWin32Window(window);
  LONG_PTR style = GetWindowLongPtr(hwnd, GWL_STYLE);
  style &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX |
             WS_SYSMENU);
  SetWindowLongPtr(hwnd, GWL_STYLE, style);
}
