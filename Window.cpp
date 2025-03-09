#include "Window.h"

Window::Window()
{
	width = 800;
	height = 600;
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
Window::Window(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
	rotax = 0.0f;
	rotay = 0.0f;
	rotaz = 0.0f;
	articulacion1 = 0.0f;
	articulacion2 = 0.0f;
	articulacion3 = 0.0f;
	articulacion4 = 0.0f;
	articulacion5 = 0.0f;
	articulacion6 = 0.0f;
	articulacion7 = 0.0f;
	articulacion8 = 0.0f;
	articulacion9 = 0.0f;
	bandera1 = 0;
	bandera2 = 0;
	bandera3 = 0;
	bandera4 = 0;
	bandera5 = 0;
	bandera6 = 0;
	bandera7 = 0;
	bandera8 = 0;
	bandera9 = 0;
	rueda1 = 0.0;
	rueda2 = 0.0;
	rueda3 = 0.0;
	rueda4 = 0.0;
	
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
int Window::Initialise()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	mainWindow = glfwCreateWindow(width, height, "Practica 4. Modelo Jerarquico", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//MANEJAR TECLADO y MOUSE
	createCallbacks();


	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST); //HABILITAR BUFFER DE PROFUNDIDAD
							 // Asignar valores de la ventana y coordenadas
							 
							 //Asignar Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);
	//Callback para detectar que se está usando la ventana
	glfwSetWindowUserPointer(mainWindow, this);
}

void Window::createCallbacks()
{
	glfwSetKeyCallback(mainWindow, ManejaTeclado);
	glfwSetCursorPosCallback(mainWindow, ManejaMouse);
}

GLfloat Window::getXChange()
{
	GLfloat theChange = xChange;
	xChange = 0.0f;
	return theChange;
}

GLfloat Window::getYChange()
{
	GLfloat theChange = yChange;
	yChange = 0.0f;
	return theChange;
}

void Window::ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}

	
	if (key == GLFW_KEY_E)
	{
		theWindow->rotax += 10.0;
	}
	if (key == GLFW_KEY_R)
	{
		theWindow->rotay += 10.0; //rotar sobre el eje y 10 grados
	}
	if (key == GLFW_KEY_T)
	{
		theWindow->rotaz += 10.0;
	}
	if (key == GLFW_KEY_F)
	{
		if (theWindow->articulacion1 < 30.0 && theWindow->bandera1 == 0) {
			theWindow->articulacion1 += 10.0;
		}
		else if (theWindow->articulacion1 == 30.0) {
			theWindow->bandera1 = 1;
			theWindow->articulacion1 -= 10.0;
		}
		else if (theWindow->articulacion1 > -10.0 && theWindow->bandera1 == 1) {
			theWindow->articulacion1 -= 10.0;
		}
		else {
			theWindow->bandera1 = 0;
			theWindow->articulacion1 += 10.0;
		}
	}

	if (key == GLFW_KEY_G)
	{
		if (theWindow->articulacion2 < 10.0 && theWindow->bandera2 == 0) {
			theWindow->articulacion2 += 10.0;
		}else if (theWindow->articulacion2 == 10.0) {
			theWindow->bandera2 = 1;
			theWindow->articulacion2 -= 10.0;
		}else if (theWindow->articulacion2 > -10.0 && theWindow->bandera2 == 1) {
			theWindow->articulacion2 -= 10.0;
		}else {
			theWindow->bandera2 = 0;
			theWindow->articulacion2 += 10.0;
		}
	}
	if (key == GLFW_KEY_H)
	{
		if (theWindow->articulacion3 < 30.0 && theWindow->bandera3 == 0) {
			theWindow->articulacion3 += 10.0;
		}else if (theWindow->articulacion3 == 30.0) {
			theWindow->bandera3 = 1;
			theWindow->articulacion3 -= 10.0;
		}else if (theWindow->articulacion3 > -10.0 && theWindow->bandera3 == 1) {
			theWindow->articulacion3 -= 10.0;
		}else {
			theWindow->bandera3 = 0;
			theWindow->articulacion3 += 10.0;
		}
	}
	if (key == GLFW_KEY_J)
	{
		if (theWindow->articulacion4 < 10.0 && theWindow->bandera4 == 0) {
			theWindow->articulacion4 += 10.0;
		}else if (theWindow->articulacion4 == 10.0) {
			theWindow->bandera4 = 1;
			theWindow->articulacion4 -= 10.0;
		}else if (theWindow->articulacion4 > -10.0 && theWindow->bandera4 == 1) {
			theWindow->articulacion4 -= 10.0;
		}else {
			theWindow->bandera4 = 0;
			theWindow->articulacion4 += 10.0;
		}
	}
	if (key == GLFW_KEY_K)
	{
		if (theWindow->articulacion5 < 30.0 && theWindow->bandera5 == 0) {
			theWindow->articulacion5 += 10.0;
		}else if (theWindow->articulacion5 == 30.0) {
			theWindow->bandera5 = 1;
			theWindow->articulacion5 -= 10.0;
		}else if (theWindow->articulacion5 > -10.0 && theWindow->bandera5 == 1) {
			theWindow->articulacion5 -= 10.0;
		}else {
			theWindow->bandera5 = 0;
			theWindow->articulacion5 += 10.0;
		}
	}
	if (key == GLFW_KEY_L)
	{
		if (theWindow->articulacion6 < 10.0 && theWindow->bandera6 == 0) {
			theWindow->articulacion6 += 10.0;
		}else if (theWindow->articulacion6 == 10.0) {
			theWindow->bandera6 = 1;
			theWindow->articulacion6 -= 10.0;
		}else if (theWindow->articulacion6 > -10.0 && theWindow->bandera6 == 1) {
			theWindow->articulacion6 -= 10.0;
		}else {
			theWindow->bandera6 = 0;
			theWindow->articulacion6 += 10.0;
		}
	}
	if (key == GLFW_KEY_I)
	{
		if (theWindow->articulacion7 < 30.0 && theWindow->bandera7 == 0) {
			theWindow->articulacion7 += 10.0;
		}else if (theWindow->articulacion7 == 30.0) {
			theWindow->bandera7 = 1;
			theWindow->articulacion7 -= 10.0;
		}else if (theWindow->articulacion7 > -10.0 && theWindow->bandera7 == 1) {
			theWindow->articulacion7 -= 10.0;
		}else {
			theWindow->bandera7 = 0;
			theWindow->articulacion7 += 10.0;
		}
	}
	if (key == GLFW_KEY_O)
	{
		if (theWindow->articulacion8 < 10.0 && theWindow->bandera8 == 0) {
			theWindow->articulacion8 += 10.0;
		}else if (theWindow->articulacion8 == 10.0) {
			theWindow->bandera8 = 1;
			theWindow->articulacion8 -= 10.0;
		}else if (theWindow->articulacion8 > -10.0 && theWindow->bandera8 == 1) {
			theWindow->articulacion8 -= 10.0;
		}else {
			theWindow->bandera8 = 0;
			theWindow->articulacion8 += 10.0;
		}
	}
	if (key == GLFW_KEY_P)
	{
		if (theWindow->articulacion9 < 60.0 && theWindow->bandera9 == 0) {
			theWindow->articulacion9 += 10.0;
		}else if (theWindow->articulacion9 == 60.0) {
			theWindow->bandera9 = 1;
			theWindow->articulacion9 -= 10.0;
		}else if (theWindow->articulacion9 > -60.0 && theWindow->bandera9 == 1) {
			theWindow->articulacion9 -= 10.0;
		}else {
			theWindow->bandera9 = 0;
			theWindow->articulacion9 += 10.0;
		}
	}
	if (key == GLFW_KEY_V)
	{
		theWindow->rueda1 += 10.0;
	}
	if (key == GLFW_KEY_B)
	{
		theWindow->rueda2 += 10.0;
	}
	if (key == GLFW_KEY_N)
	{
		theWindow->rueda3 += 10.0;
	}
	if (key == GLFW_KEY_M)
	{
		theWindow->rueda4 += 10.0;
	}


	if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		const char* key_name = glfwGetKeyName(GLFW_KEY_D, 0);
		//printf("se presiono la tecla: %s\n",key_name);
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			theWindow->keys[key] = true;
			//printf("se presiono la tecla %d'\n", key);
		}
		else if (action == GLFW_RELEASE)
		{
			theWindow->keys[key] = false;
			//printf("se solto la tecla %d'\n", key);
		}
	}
}

void Window::ManejaMouse(GLFWwindow* window, double xPos, double yPos)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (theWindow->mouseFirstMoved)
	{
		theWindow->lastX = xPos;
		theWindow->lastY = yPos;
		theWindow->mouseFirstMoved = false;
	}

	theWindow->xChange = xPos - theWindow->lastX;
	theWindow->yChange = theWindow->lastY - yPos;

	theWindow->lastX = xPos;
	theWindow->lastY = yPos;
}


Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();

}
