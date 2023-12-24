using LW8;
using LW8_Gorgun.Utils;

var integral1 = new Integral();
var integral2 = new Integral();

var indicator1 = new CompIndicator();
var indicator2 = new CompIndicator();

integral1.OnCalcEvent += indicator1.IndicatorProc;
integral2.OnCalcEvent += indicator2.IndicatorProc;

integral1.OnFinishEvent += indicator1.IndicateFinish;
integral2.OnFinishEvent += indicator2.IndicateFinish;

var cntThread1 = new Thread(() => integral1.GetIntegralSin()) { Priority = ThreadPriority.Highest };
var cntThread2 = new Thread(() => integral1.GetIntegralSin()) { Priority = ThreadPriority.Lowest };

cntThread1.Start();
cntThread2.Start();


for(int i = 0; i<5; i++) // #4
{
    var integralComputer = new Integral();
    var indicator = new CompIndicator();
    integralComputer.OnCalcEvent += indicator.IndicatorProc;
    integralComputer.OnFinishEvent += indicator.IndicateFinish;
    var countedThread = new Thread(() => integralComputer.GetIntegralSin());
    countedThread.Start();
}