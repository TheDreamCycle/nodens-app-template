/*	Set this file as the Startup Item for CMakeLists.txt
 */

#define MAIN_APPLICATION_FILE
#include "NodensTemplateLayer.h"
#include "nodens.h"

// Main application layer
class NodensTemplateApp : public Nodens::Application
{
public:
    NodensTemplateApp(const Nodens::WindowProps props)
        : Application(props)
    {
        PushLayer(new NodensTemplateLayer());
    }

    ~NodensTemplateApp() {}
};

Nodens::Application *Nodens::CreateApplication()
{
    return new NodensTemplateApp(Nodens::WindowProps("Nodens Template App", 800, 600, false));
}