#using <System.dll>

using namespace System;
using namespace System::Timers;


void OnElapsed(System::Object^ sender, System::Timers::ElapsedEventArgs^ e);
int main()
{
	Timer^ MyTimer = gcnew Timer(500);
	MyTimer->AutoReset = true;
	MyTimer->Elapsed += gcnew System::Timers::ElapsedEventHandler(&OnElapsed);
	MyTimer->Start();
	Console::ReadKey();
	MyTimer->Stop();
	Console::CursorVisible = true;

	return 0;
}
void OnElapsed(System::Object^ sender, System::Timers::ElapsedEventArgs^ e)
{
	Console::CursorVisible = false;
	Console::SetCursorPosition(20, 2);
	Console::WriteLine(DateTime::Now);
}
