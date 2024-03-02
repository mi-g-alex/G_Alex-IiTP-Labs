using System.Globalization;
using Lab_1_4.Pages.ProgressBar;

namespace Lab_1_4.ProgressBar;

public partial class ProgressBarPage : ContentPage
{
    private ProgressClass ProgressValue { get; set; }

    private CancellationTokenSource CancelTokenSource { get; set; }
    private CancellationToken Token { get; set; }

    public ProgressBarPage()
    {
        InitializeComponent();
        EndBtn.IsEnabled = false;
        // ProgressValue = new ProgressClass();
        // var a = new Binding { Source = ProgressValue, Path = "Progress" };
        // PbMain.SetBinding(ProgressBar.ProgressProperty, a);
    }


    private async void StartProgress(object sender, EventArgs e)
    {
        CancelTokenSource = new CancellationTokenSource();
        Token = CancelTokenSource.Token;
        LMainText.Text = "Вычисление";
        StartBtn.IsEnabled = false;
        EndBtn.IsEnabled = true;
        try
        {
            await Integrate(Token);
        }
        catch (OperationCanceledException)
        {
            CancelTokenSource.Dispose();
        }
    }

    private async Task Integrate(CancellationToken token)
    {
        const double step = 3e-4;
        var sum = 0.0;
        var it = 0.0;

        ProgressValue = Resources["ProgressClassKey"] as ProgressClass;

        const int steps = (int)(1d / step);
        for (var i = 0; i < steps; i++)
        {
            token.ThrowIfCancellationRequested();
            await Task.Delay(1, token);
            sum += step * Math.Sin(it);
            it += step;
            for (var j = 0; j < 1000; j++)
            {
                var a = j * j;
            }

            if (ProgressValue != null) ProgressValue.Progress = Convert.ToDouble(i + 1) / steps;
        }

        LMainText.Text = "Результат: " + sum.ToString(CultureInfo.InvariantCulture);
        StartBtn.IsEnabled = true;
        EndBtn.IsEnabled = false;
    }

    private void EndProgress(object sender, EventArgs e)
    {
        try
        {
            CancelTokenSource.Cancel();
        }
        catch
        {
            // ignored
        }

        LMainText.Text = "Задание отменено";
        StartBtn.IsEnabled = true;
        EndBtn.IsEnabled = false;
    }
}