#pragma once

#include "nodens.h" // Nodens Engine lib

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/vector_angle.hpp"

#include "imgui/imgui.h"
#include "implot/implot.h"
#include "implot3d/implot3d.h"

#include <fstream>
#include <list>


class NodensTemplateLayer : public Nodens::Layer {
public:
	// Nodens Engine Functions =========================================================================================
	/**
	 *   \brief The constructor is called only once when the layer is created in the stack.
	 */
	NodensTemplateLayer();

	/**
	 *   \brief This function is called once per frame.
	 */
	void OnUpdate(Nodens::TimeStep ts) override;

	/**
	 *   \brief This function is called once per frame after OnUpdate.
	 */
	void OnImGuiRender(Nodens::TimeStep ts) override;

	void OnEvent(Nodens::Event& event) override;
	bool OnWindowResizeEvent(Nodens::WindowResizeEvent& event);

private:
	// Template Variables ==============================================================================================
	float xs[1001], ys[1001];
	float xs3d[1001], ys3d[1001], zs3d[1001];
};
