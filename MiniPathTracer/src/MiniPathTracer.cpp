#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
#include "Walnut/Image.h"

class MiniPathTracer : public Walnut::Layer {
public:
  virtual void OnUIRender() override {
    ImGui::Begin("Hello");
    ImGui::Button("Button");
    ImGui::End();

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("Viewport");
    ImGui::End();
    ImGui::PopStyleVar();

    ImGui::ShowDemoWindow();

    // Render();
  }
};
void Render() {
  // // ZoneScopedN("render");

  // Timer timer;

  // renderer_.OnResize(viewportWidth_, viewportHeight_);
  // mCamera_.OnResize(viewportWidth_, viewportHeight_);
  // renderer_.Render(scene_, mCamera_);

  // lastRenderTime_ = timer.ElapsedMillis();
}

Walnut::Application* Walnut::CreateApplication(int argc, char** argv) {
  Walnut::ApplicationSpecification spec;
  spec.Name = "MiniPathTracer";

  Walnut::Application* app = new Walnut::Application(spec);
  app->PushLayer<MiniPathTracer>();
  app->SetMenubarCallback([app]() {
    if (ImGui::BeginMenu("File")) {
      if (ImGui::MenuItem("Exit")) {
        app->Close();
      }
      ImGui::EndMenu();
    }
  });
  return app;
}