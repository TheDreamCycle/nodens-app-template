#include "NodensTemplateLayer.h"

NodensTemplateLayer::NodensTemplateLayer()
    : Layer("TemplateLayer")
{
    // Set ImGui theme
    ImGui::StyleColorsDark();

	// Generate data for ImPlot
	for (int i = 0; i < 1001; i++)
	{
		xs[i] = i * 0.001f;
		ys[i] = sin(10 * 3.1415 * xs[i]);
	}
	for (int i = 0; i < 1001; i++)
	{
		xs3d[i] = i * 0.001f;
		ys3d[i] = sin(10 * 3.1415 * xs3d[i]);
		zs3d[i] = cos(10 * 3.1415 * xs3d[i]);
	}
} // TemplateLayer::TemplateLayer

void NodensTemplateLayer::OnUpdate(Nodens::TimeStep previous_update_duration)
{
} // TemplateLayer::OnUpdate

void NodensTemplateLayer::OnImGuiRender(Nodens::TimeStep ts)
{
	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport()->ID);
	
	// Implot example
	ImGui::Begin("ImPlot Example");
    if (ImPlot::BeginPlot("Sine Wave", "x", "y"))
    {
	    ImPlot::PlotLine("Sine Wave", xs, ys, 1001);
	    ImPlot::EndPlot();
    }
	ImGui::End();

	// Implot3D example
	ImGui::Begin("ImPlot3D Example");
    if (ImPlot3D::BeginPlot("Sine Wave 3D"))
    {
	    ImPlot3D::PlotLine("Sine Wave 3D", xs3d, ys3d, zs3d, 1001);
	    ImPlot3D::EndPlot();
    }
    ImGui::End();
    

} // TemplateLayer::OnImGuiRender


void NodensTemplateLayer::OnEvent(Nodens::Event& event)
{
    Nodens::EventDispatcher dispatcher(event);
    dispatcher.Dispatch<Nodens::WindowResizeEvent>(ND_BIND_EVENT_FN(NodensTemplateLayer::OnWindowResizeEvent));
} // TemplateLayer::OnEvent


bool NodensTemplateLayer::OnWindowResizeEvent(Nodens::WindowResizeEvent& event)
{
    return true;
} // TemplateLayer::OnMouseMovedEvent
