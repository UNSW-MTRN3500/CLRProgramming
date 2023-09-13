#using <System.dll>

using namespace System;
using namespace System::Threading;

ref class OurThreads
{
	static Barrier^ ThreadBarrier;
public:
	static bool Quit;
	OurThreads()
	{
		ThreadBarrier = gcnew Barrier(2);
		Quit = false;
	}
	static void Lidar()
	{
		Console::WriteLine("Enterd Lidar routine.");
		Thread::Sleep(5000);
		Console::WriteLine("Lidar Ready");
		ThreadBarrier->SignalAndWait();
		while (!Quit)
		{
			Console::WriteLine("Laser scan Completed!");
			Thread::Sleep(50);
		}
	}

	static void GNSS()
	{
		Console::WriteLine("Enterd GNSS routine.");
		Thread::Sleep(1000);
		Console::WriteLine("GNSS Ready");
		ThreadBarrier->SignalAndWait();
		while (!Quit)
		{
			Console::WriteLine("GNSS scan Completed!");
			Thread::Sleep(50);
		}
	}
};

int main()
{
	OurThreads^ VehicleThreads = gcnew OurThreads;
	Thread^ LidarThread = gcnew Thread(gcnew ThreadStart(VehicleThreads->Lidar));
	Thread^ GNSSThread = gcnew Thread(gcnew ThreadStart(VehicleThreads->GNSS));

	LidarThread->Start();
	GNSSThread->Start();

	Console::ReadKey();
	VehicleThreads->Quit = true;
	Console::ReadKey();

	return 0;
}