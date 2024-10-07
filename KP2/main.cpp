#include <iostream>
#include "cl_app.h"
int main()
{
	// program here
	cl_app app(nullptr);
	app.build();
	return app.exec();
}
