
#include "app/App.cpp"
#include <iostream>

int main(int argc, char* argv[])
{
    App* app = new App;

    app->Init();

    app->Run();

    app->Quit();

    return 0;
}