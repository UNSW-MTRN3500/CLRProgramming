#using <System.dll>

using namespace System;
using namespace System::Threading;

void Lidar();
void GNSS();
bool Quit =  false;

int main()
{
	Thread^ GNSSThread = gcnew Thread(gcnew ThreadStart(GNSS));
	Thread^ LidarThread = gcnew Thread(gcnew ThreadStart(Lidar));

	GNSSThread->Start();
	LidarThread->Start();
	Console::ReadKey();
	Quit = true;
	Console::ReadKey();

	return 0;
}

void Lidar()
{
	while(!Quit)
	{
		Console::WriteLine("Laser scan acquired");
		Thread::Sleep(50);
	}
}

void GNSS()
{
	while (!Quit)
	{
		Console::WriteLine("GNSS acquisition completed");
		Thread::Sleep(50);
	}
}