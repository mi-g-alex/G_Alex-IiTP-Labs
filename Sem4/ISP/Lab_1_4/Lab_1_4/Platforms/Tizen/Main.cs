using System;
using Microsoft.Maui;
using Microsoft.Maui.Hosting;

namespace Gorgun_253501_Labs1_4;

class Program : MauiApplication
{
	protected override MauiApp CreateMauiApp() => MauiProgram.CreateMauiApp();

	static void Main(string[] args)
	{
		var app = new Program();
		app.Run(args);
	}
}
