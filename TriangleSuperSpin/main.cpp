//
//  main.cpp
//  Transformations
//
//  Created by Logan Hoelscher on 10/5/19.
//  Copyright © 2019 Logan Hoelscher. All rights reserved.
//

#include <iostream>
#include "Shader.h"
#include "matrix.hpp"
#include "mat4x4.hpp"
#include "vec3.hpp"
#include "trigonometric.hpp"
#include "geometric.hpp"
#include "glm.hpp"
#include "matrix_transform.hpp"
#include "type_ptr.hpp"


// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
GLint objectToWorldUniformLocation;



// The main function
int main( )
{
    // Init GLFW
    glfwInit( );
    
    // Set all the required options for GLFW
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    
    glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
    
    // Create a GLFWwindow object
    GLFWwindow *window = glfwCreateWindow( WIDTH, HEIGHT, "Transformations", nullptr, nullptr );
    int screenWidth, screenHeight;
    glfwGetFramebufferSize( window, &screenWidth, &screenHeight );
    
    if ( nullptr == window )
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate( );
        
        return EXIT_FAILURE;
    }
    
    glfwMakeContextCurrent( window );
    
    
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if ( GLEW_OK != glewInit( ) )
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Define the viewport dimensions
    glViewport( 0, 0, screenWidth, screenHeight );
    
    // Build and compile our shader program
    Shader ourShader( "resources/shader/core.vs", "resources/shader/core.frag" );
    
    
    // vertices smaller triangle
    GLfloat vertices[] =
    {
        //vertex                    color
        0.0f, 0.5f, 0.0f,        0.439216f, 0.858824f, 0.576471f, // top vertex
        0.5f, -0.5f, 0.0f,         0.917647f, 0.678431f, 0.917647f, // bottom right vertex
        -0.5f, -0.5f, 0.0f,        1.0f, 1.0f, 0.0f  // bottom left vertex
    };
    
    
    
    /***************************** Begin smaller triangle ******************************/
    GLuint VBO, VAO;
    glGenVertexArrays( 1, &VAO );
    glGenBuffers( 1, &VBO );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO );
    
    glBindBuffer( GL_ARRAY_BUFFER, VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /*********************** End smaller triangle ***************************************/
    

    // event loop
    while ( !glfwWindowShouldClose( window ) )
    {
        // Check for events
        glfwPollEvents( );
        
        // Render
        // Clear the colorbuffer
        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
        //glClear( GL_COLOR_BUFFER_BIT );
        
        static float angle = 0;
        glm::mat4 Xfm = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0, 1.0, 0.0));
        glUniformMatrix4fv(objectToWorldUniformLocation, 1, GL_FALSE, glm::value_ptr(Xfm));
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ourShader.Use( );
        glBindVertexArray( VAO );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        angle += .05;
        if (angle > 360) angle = 0;
        
        /*
        // Draw the smaller triangle
        ourShader.Use( );
        glBindVertexArray( VAO );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
         */
        
        // Swap the screen buffers
        glfwSwapBuffers( window );
    }
    
    // Properly de-allocate all resources
    glDeleteVertexArrays( 1, &VAO );
    glDeleteBuffers( 1, &VBO );
    
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate( );
    
    return EXIT_SUCCESS;
}




