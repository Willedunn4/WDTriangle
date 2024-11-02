#include <GL/glut.h>  // Include the GLUT library
#include <cmath>

// Rotation angle
float angle = 0.0f;

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color to black
    glColor3f(1.0, 1.0, 1.0);          // Set drawing color to white
    glPointSize(4.0);                  // Set point size
    glMatrixMode(GL_PROJECTION);       // Set projection parameters
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  // Set the coordinate system
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);      // Clear the screen
    glLoadIdentity();                  // Reset transformations

    // Rotate the triangle
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Draw the triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);          // Red
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0, 1.0, 0.0);          // Green
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0, 0.0, 1.0);          // Blue
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glutSwapBuffers();  // Swap buffers for smooth animation
}

// Timer function to update the rotation angle
void timer(int value) {
    angle += 1.0f;                     // Increment the rotation angle
    if (angle > 360.0f)                // Reset angle if over 360 degrees
        angle -= 360.0f;
    glutPostRedisplay();               // Mark the window for redisplay
    glutTimerFunc(16, timer, 0);       // Recall the timer after 16 ms (~60 FPS)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   // Set display mode
    glutInitWindowSize(500, 500);                  // Set window size
    glutCreateWindow("Rotating Triangle");         // Create window with title
    init();                                        // Initialize OpenGL settings
    glutDisplayFunc(display);                      // Set display function
    glutTimerFunc(0, timer, 0);                    // Set the timer function
    glutMainLoop();                                // Enter the main loop
    return 0;
}