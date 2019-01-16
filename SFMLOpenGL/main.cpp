//
//  main.cpp
//  SFMLOpenGL
//
//  Created by Jesús Eloi on 16/01/2019.
//  Copyright © 2019 Eloi. All rights reserved.
//

#include <iostream>
#define GLEW_STATIC

#include <GL/glew.h>
#include <SFML/Window.hpp>

const GLint WIDTH = 800, HEIGHT = 600;

const GLChar *vertexShaderSource

int main ()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.attributeFlags = sf::ContextSettings::Core;
    
    sf::Window window(sf::VideoMode(WIDTH, HEIGHT, 32), "OPENGL SFML", sf::Style::Titlebar |sf::Style::Close, settings);
    
    glewExperimental = GL_TRUE;
    
    if (GLEW_OK != glewInit()) {
        std::cout<< "Failed to initialize GLEW" << std::endl;
        
        return EXIT_FAILURE;
    }
    
    bool running = true;
    
    while (running) {
        sf::Event windowEvent;
        
        while (window.pollEvent(windowEvent)) {
            switch (windowEvent.type) {
                case sf::Event::Closed:
                    running = false;
                    break;
            }
        }
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //draw OpenGL
        
        window.display();
        
            }
    
    window.close();
    
    return EXIT_SUCCESS;

}
