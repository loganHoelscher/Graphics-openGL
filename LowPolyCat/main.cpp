//
//  main.cpp
//  Extra Geometry
//
//  Created by Logan Hoelscher on 10/7/19.
//  Copyright © 2019 Logan Hoelscher. All rights reserved.
//

#include <iostream>
#include "Shader.h"
#include "matrix.hpp"
#include "mat4x4.hpp"
#include "vec3.hpp"
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
float speed;

GLuint VBO19, VAO19;
GLuint VBO18, VAO18;
GLuint VBO17, VAO17;
GLuint VBO16, VAO16;



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
    GLFWwindow *window = glfwCreateWindow( WIDTH, HEIGHT, "Low Poly Cat", nullptr, nullptr );
    
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
    Shader altShader( "resources/shader/altcore.vs", "resources/shader/core.frag" );
    
    
    
    // vertices mid right triangle
    GLfloat vertices[] =
    {
        //vertex                    color
        0.0f, -0.2f, 0.0f,        1.0f, 0.5f, 0.0f, // top vertex
        0.0f, 0.6f, 0.0f,         1.0f, 0.5f, 0.0f, // bottom right vertex
        0.4f, 0.4f, 0.0f,        1.0f, 0.5f, 0.0f  // bottom left vertex
    };
    
    GLfloat midLeft[] =
    {
        //vertex                    color
        0.0f, -0.2f, 0.0f,      0.89f, 0.37f, 0.20f,
        0.0f, 0.6f, 0.0f,       0.89f, 0.37f, 0.20f,
        -0.4f, 0.4f, 0.0f,      0.89f, 0.37f, 0.20f
        
    };
    
    GLfloat cheekRight[] =
    {
        //vertex                    color
        0.0f, -0.2f, 0.0f,      0.90f, 0.90f, 0.90f,
        0.6f, -0.2f, 0.0f,      0.90f, 0.90f, 0.90f,
        0.4f, 0.4f, 0.0f,      0.90f, 0.90f, 0.90f
    };
    
    GLfloat cheekLeft[] =
    {
        //vertex                    color
        0.0f, -0.2f, 0.0f,      0.758824f, 0.758824f, 0.758824f,
        -0.6f, -0.2f, 0.0f,       0.758824f, 0.758824f, 0.758824f,
        -0.4f, 0.4f, 0.0f,      0.758824f, 0.758824f, 0.758824f
    };
    
    GLfloat jawRight[] =
    {
        //vertex                    color
        0.4f, -0.4f, 0.0f,      0.822941f, 0.822941f, 0.822941f,
        0.6f, -0.2f, 0.0f,       0.822941f, 0.822941f, 0.822941f,
        0.2f, -0.2f, 0.0f,      0.822941f, 0.822941f, 0.822941f
    };
    
    GLfloat jawLeft[] =
    {
        //vertex                    color
        -0.4f, -0.4f, 0.0f,      0.692941f, 0.692941f, 0.692941f,
        -0.6f, -0.2f, 0.0f,       0.692941f, 0.692941f, 0.692941f,
        -0.2f, -0.2f, 0.0f,      0.692941f, 0.692941f, 0.692941f
    };
    
    GLfloat whiskerRight[] =
    {
        //vertex                    color
        0.4f, -0.4f, 0.0f,      0.90f, 0.90f, 0.90f,
        0.0f, -0.4f, 0.0f,       0.90f, 0.90f, 0.90f,
        0.2f, -0.2f, 0.0f,      0.90f, 0.90f, 0.90f
    };
    
    GLfloat whiskerLeft[] =
    {
        //vertex                    color
        -0.4f, -0.4f, 0.0f,      0.858824f, 0.858824f, 0.858824f,
        0.0f, -0.4f, 0.0f,       0.858824f, 0.858824f, 0.858824f,
        -0.2f, -0.2f, 0.0f,      0.858824f, 0.858824f, 0.858824f
    };
    
    GLfloat noseRight[] =
    {
        //vertex                    color
        0.0f, -0.4f, 0.0f,      0.82f, 0.49f, 0.49f,
        0.0f, -0.2f, 0.0f,       0.82f, 0.49f, 0.49f,
        0.2f, -0.2f, 0.0f,      0.82f, 0.49f, 0.49f
    };
    
    GLfloat noseLeft[] =
    {
        //vertex                    color
        0.0f, -0.4f, 0.0f,      0.82f, 0.29f, 0.29f,
        0.0f, -0.2f, 0.0f,       0.82f, 0.29f, 0.29f,
        -0.2f, -0.2f, 0.0f,      0.82f, 0.29f, 0.29f
    };
    
    GLfloat chinRight[] =
    {
        //vertex                    color
        0.4f, -0.4f, 0.0f,      0.822941f, 0.822941f, 0.822941f,
        0.0f, -0.4f, 0.0f,       0.822941f, 0.822941f, 0.822941f,
        0.0f, -0.7f, 0.0f,      0.822941f, 0.822941f, 0.822941f
    };
    
    GLfloat chinLeft[] =
    {
        //vertex                    color
        -0.4f, -0.4f, 0.0f,     0.692941f, 0.692941f, 0.692941f,
        0.0f, -0.4f, 0.0f,       0.692941f, 0.692941f, 0.692941f,
        0.0f, -0.7f, 0.0f,      0.692941f, 0.692941f, 0.692941f
    };
    
    GLfloat rightEarTop[] =
    {
        //vertex                    color
        0.2f, 0.5f, 0.0f,        1.0f, 0.5f, 0.0f, // top vertex
        0.5f, 0.8f, 0.0f,         1.0f, 1.0f, 1.0f, // bottom right vertex
        0.4f, 0.4f, 0.0f,        1.0f, 0.5f, 0.0f  // bottom left vertex
    };
    
    GLfloat leftEarTop[] =
    {
        //vertex                    color
        -0.2f, 0.5f, 0.0f,        0.99f, 0.37f, 0.20, // top vertex
        -0.5f, 0.8f, 0.0f,         1.0f, 1.0f, 1.0f, // bottom right vertex
        -0.4f, 0.4f, 0.0f,        0.89f, 0.37f, 0.20f  // bottom left vertex
    };
    
    GLfloat rightEar[] =
    {
        //vertex                    color
        0.467f, 0.2f, 0.0f,        0.8f, 0.8f, 0.8f, // top vertex
        0.5f, 0.8f, 0.0f,         0.82f, 0.49f, 0.49f, // bottom right vertex
        0.4f, 0.4f, 0.0f,        0.82f, 0.49f, 0.49f  // bottom left vertex
    };
    
    GLfloat leftEar[] =
    {
        //vertex                    color
        -0.467f, 0.2f, 0.0f,        0.4f, 0.4f, 0.4f, // top vertex
        -0.5f, 0.8f, 0.0f,         0.82f, 0.29f, 0.29f, // bottom right vertex
        -0.4f, 0.4f, 0.0f,        0.82f, 0.29f, 0.29f  // bottom left vertex
    };
    
    GLfloat rightEyeTop[] =
    {
        0.22f, 0.1f, 0.0f,       0.560784f, 0.560784f, 0.737255f,
        0.25f, 0.25f, 0.0f,     0.0f, 0.0f, 0.0f,
        0.28f, 0.1f, 0.f,       0.0f, 0.0f, 0.0f
    };
    
    GLfloat leftEyeTop[] =
    {
        -0.22f, 0.1f, 0.0f,       0.0f, 0.0f, 0.0f,
        -0.25f, 0.25f, 0.0f,     0.0f, 0.0f, 0.0f,
        -0.28f, 0.1f, 0.f,       0.560784f, 0.560784f, 0.737255f
    };
    
    GLfloat rightEye[] =
    {
        0.22f, 0.1f, 0.0f,       0.560784f, 0.560784f, 0.737255f,
        0.25f, -0.05f, 0.0f,     0.0f, 0.0f, 0.0f,
        0.28f, 0.1f, 0.f,        0.0f, 0.0f, 0.0f
    };
    
    GLfloat leftEye[] =
    {
        -0.22f, 0.1f, 0.0f,       0.0f, 0.0f, 0.0f,
        -0.25f, -0.05f, 0.0f,     0.0f, 0.0f, 0.0f,
        -0.28f, 0.1f, 0.f,        0.560784f, 0.560784f, 0.737255f
    };
    
    
    
    /***************************** Begin mid right ******************************/
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
    /*********************** End mid right ***************************************/
    
    /***************************** Begin mid left ******************************/
    GLuint VBO1, VAO1;
    glGenVertexArrays( 1, &VAO1 );
    glGenBuffers( 1, &VBO1 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO1 );
    
    glBindBuffer( GL_ARRAY_BUFFER, VBO1 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(midLeft), midLeft, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end mid right ******************************/
    
    /***************************** Begin cheekRight ******************************/
    GLuint VBO2, VAO2;
    glGenVertexArrays( 1, &VAO2 );
    glGenBuffers( 1, &VBO2 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO2 );
    
    glBindBuffer( GL_ARRAY_BUFFER, VBO2 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(cheekRight), cheekRight, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end cheekRight ******************************/
    
     /***************************** Begin cheekLeft ******************************/
    GLuint VBO3, VAO3;
    glGenVertexArrays( 1, &VAO3 );
    glGenBuffers( 1, &VBO3 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO3 );
    
    glBindBuffer( GL_ARRAY_BUFFER, VBO3 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(cheekLeft), cheekLeft, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
     /***************************** end cheekLeft ******************************/
    
    /***************************** Begin jawRight ******************************/
    GLuint VBO4, VAO4;
    glGenVertexArrays( 1, &VAO4 );
    glGenBuffers( 1, &VBO4 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO4 );
    
    glBindBuffer( GL_ARRAY_BUFFER, VBO4 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(jawRight), jawRight, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
      /***************************** end jawRight ******************************/
    
    /***************************** Begin jawLeft ******************************/
    GLuint VBO5, VAO5;
    glGenVertexArrays( 1, &VAO5 );
    glGenBuffers( 1, &VBO5 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO5 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO5 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(jawLeft), jawLeft, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end jawLeft ******************************/
    
    /***************************** Begin whiskerRight ******************************/
    GLuint VBO6, VAO6;
    glGenVertexArrays( 1, &VAO6 );
    glGenBuffers( 1, &VBO6 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO6 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO6 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(whiskerRight), whiskerRight, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end whiskerRight ******************************/
    
    /***************************** Begin whiskerLeft ******************************/
    GLuint VBO7, VAO7;
    glGenVertexArrays( 1, &VAO7 );
    glGenBuffers( 1, &VBO7 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO7 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO7 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(whiskerLeft), whiskerLeft, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end whiskerLeft ******************************/
    
    /***************************** Begin noseRight ******************************/
    GLuint VBO8, VAO8;
    glGenVertexArrays( 1, &VAO8 );
    glGenBuffers( 1, &VBO8 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO8 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO8 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(noseRight), noseRight, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end noseRight ******************************/
    
    /***************************** Begin noseLeft ******************************/
    GLuint VBO9, VAO9;
    glGenVertexArrays( 1, &VAO9 );
    glGenBuffers( 1, &VBO9 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO9 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO9 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(noseLeft), noseLeft, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end noseleft ******************************/
    
    /***************************** Begin chinRight ******************************/
    GLuint VBO10, VAO10;
    glGenVertexArrays( 1, &VAO10 );
    glGenBuffers( 1, &VBO10 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO10 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO10 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(chinRight), chinRight, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end chinRight ******************************/
    
    /***************************** Begin chinLeft ******************************/
    GLuint VBO11, VAO11;
    glGenVertexArrays( 1, &VAO11 );
    glGenBuffers( 1, &VBO11 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO11 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO11 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(chinLeft), chinLeft, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end chinLeft ******************************/
    
    /***************************** Begin rightEarTop ******************************/
    GLuint VBO12, VAO12;
    glGenVertexArrays( 1, &VAO12 );
    glGenBuffers( 1, &VBO12 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO12 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO12 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(rightEarTop), rightEarTop, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end rightEarTop ******************************/
    
    /***************************** Begin leftEartop ******************************/
    GLuint VBO13, VAO13;
    glGenVertexArrays( 1, &VAO13 );
    glGenBuffers( 1, &VBO13 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO13 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO13 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(leftEarTop), leftEarTop, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end leftEarTop ******************************/
    
    /***************************** Begin rightEar ******************************/
    GLuint VBO14, VAO14;
    glGenVertexArrays( 1, &VAO14 );
    glGenBuffers( 1, &VBO14 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO14 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO14 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(rightEar), rightEar, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end rightEar ******************************/
    
    /***************************** Begin leftEar ******************************/
    GLuint VBO15, VAO15;
    glGenVertexArrays( 1, &VAO15 );
    glGenBuffers( 1, &VBO15 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO15 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO15 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(leftEar), leftEar, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end leftEar ******************************/
    
    /***************************** Begin rightEyeTop ******************************/
    
    glGenVertexArrays( 1, &VAO16 );
    glGenBuffers( 1, &VBO16 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO16 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO16 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(rightEyeTop), rightEyeTop, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end rightEyeTop ******************************/
    
    /***************************** Begin leftEyeTop ******************************/
    
    glGenVertexArrays( 1, &VAO17 );
    glGenBuffers( 1, &VBO17 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO17 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO17 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(leftEyeTop), leftEyeTop, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end leftEyeTop ******************************/
    
    /***************************** Begin rightEye ******************************/
    
    glGenVertexArrays( 1, &VAO18 );
    glGenBuffers( 1, &VBO18 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO18 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO18 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(rightEye), rightEye, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end rightEye ******************************/
    
    /***************************** Begin leftEye ******************************/
    
    glGenVertexArrays( 1, &VAO19 );
    glGenBuffers( 1, &VBO19 );
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray( VAO19 );
    glBindBuffer( GL_ARRAY_BUFFER, VBO19 );
    glBufferData( GL_ARRAY_BUFFER, sizeof(leftEye), leftEye, GL_STATIC_DRAW );
    
    // Position attribute
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * ) 0 );
    glEnableVertexAttribArray( 0 );
    // Color attribute
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof( GLfloat ), ( GLvoid * )( 3 * sizeof( GLfloat ) ) );
    glEnableVertexAttribArray( 1 );
    
    glBindVertexArray( 0 ); // Unbind VAO
    /***************************** end leftEye ******************************/
    
   
    
    // event loop
    while ( !glfwWindowShouldClose( window ) )
    {
        // Check for events
        glfwPollEvents( );
        
        // Render
        // Clear the colorbuffer
        glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
        
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
         // Draw the mid right triangle
         ourShader.Use( );
         glBindVertexArray( VAO );
         glDrawArrays( GL_TRIANGLES, 0, 3 );
         glBindVertexArray(0);
        
        // Draw the mid left triangle
        ourShader.Use( );
        glBindVertexArray( VAO1 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the cheek right triangle
        ourShader.Use( );
        glBindVertexArray( VAO2 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the cheek left triangle
        ourShader.Use( );
        glBindVertexArray( VAO3 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the jawRight triangle
        ourShader.Use( );
        glBindVertexArray( VAO4 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the jawLeft triangle
        ourShader.Use( );
        glBindVertexArray( VAO5 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the whiskerRight triangle
        ourShader.Use( );
        glBindVertexArray( VAO6 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the whiskerleft triangle
        ourShader.Use( );
        glBindVertexArray( VAO7 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the noseRight triangle
        ourShader.Use( );
        glBindVertexArray( VAO8 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the noseLeft triangle
        ourShader.Use( );
        glBindVertexArray( VAO9 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the chinRight triangle
        ourShader.Use( );
        glBindVertexArray( VAO10 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the chinLeft triangle
        ourShader.Use( );
        glBindVertexArray( VAO11 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the rightEarTop triangle
        ourShader.Use( );
        glBindVertexArray( VAO12 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the leftEarTop triangle
        ourShader.Use( );
        glBindVertexArray( VAO13 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the rightEar triangle
        ourShader.Use( );
        glBindVertexArray( VAO14 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the leftEar triangle
        ourShader.Use( );
        glBindVertexArray( VAO15 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the rightEyeTop triangle
        ourShader.Use( );
        glBindVertexArray( VAO16 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the leftEyeTop triangle
        ourShader.Use( );
        glBindVertexArray( VAO17 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        // Draw the righteye triangle
        ourShader.Use( );
        glBindVertexArray( VAO18 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
        
        // Draw the lefteye triangle
        ourShader.Use( );
        glBindVertexArray( VAO19 );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray(0);
        
       
        
        int state = glfwGetKey(window, GLFW_KEY_T);
        if(state == GLFW_PRESS)
        {
            static float angle = 0;
            
            glm::mat4 Xfm = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0, 0.0, 1.0));
            
            glUniformMatrix4fv(objectToWorldUniformLocation, 1, GL_FALSE, glm::value_ptr(Xfm));
            glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            altShader.Use( );
            glBindVertexArray( VAO16 );
            glDrawArrays( GL_TRIANGLES, 0, 3 );
            glBindVertexArray(0);
            
            altShader.Use( );
            glBindVertexArray( VAO17 );
            glDrawArrays( GL_TRIANGLES, 0, 3 );
            glBindVertexArray(0);
            
            altShader.Use( );
            glBindVertexArray( VAO18 );
            glDrawArrays( GL_TRIANGLES, 0, 3 );
            glBindVertexArray(0);
            
            altShader.Use( );
            glBindVertexArray( VAO19 );
            glDrawArrays( GL_TRIANGLES, 0, 3 );
            glBindVertexArray(0);
            
            angle += 0.1;
            if (angle > 360) angle = 0;
        }
        
        int state1 = glfwGetKey(window, GLFW_KEY_W);
        if (state1 == GLFW_PRESS)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        }
        
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

