Modified version of ImGui for use with EDK3 educational engine. 

Instructions
- Include `edk_imgui.h` instead of `imgui.h` 
- After ESAT::WindowInit, call `ImGuiInit((float)kWindowWidth, (float)kWindowHeight);`
- Before any calls to ImGui call `ImGuiNewFrame()` 
- Call `ImGuiDraw()` after `ImGui::Render()` but before `ESAT::WindowFrame()`
