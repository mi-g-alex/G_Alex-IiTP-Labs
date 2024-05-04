using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Lab5.Application.WorkUseCases.Commands;
using MediatR;

namespace Lab5.UI.ViewModels;

public partial class AddOrEditWorkViewModel(IMediator mediator) : ObservableObject, IQueryAttributable
{
    private IAddOrEditWorkRequest _request;

    public void ApplyQueryAttributes(IDictionary<string, object> query)
    {
        _request = query["Request"] as IAddOrEditWorkRequest;
        if (_request != null)
        {
            Rating = Convert.ToDouble(_request.Work.Rating);
            ImageSrc = _request.Work.ImageSrc;
            Name = _request.Work.Name;
        }

        if (_request?.Work.StartDate.Equals(new DateTime()) == true)
        {
            StartDate = DateTime.Today;
            EndDate = DateTime.Today;
        }
    }

    [ObservableProperty] private double rating;
    [ObservableProperty] private string imageSrc;
    [ObservableProperty] private string name;
    [ObservableProperty] private DateTime startDate;
    [ObservableProperty] private DateTime endDate;

    [RelayCommand]
    async Task AddOrEditWork()
    {
        _request.Work.Name = Name;
        _request.Work.StartDate = StartDate;
        _request.Work.EndDate = EndDate;
        _request.Work.ImageSrc = ImageSrc;
        _request.Work.Rating = Convert.ToInt32(Rating);
        await mediator.Send(_request);
        await GoBack();
    }

    [RelayCommand]
    async Task SelectImage()
    {
        var result = await FilePicker.PickAsync(new PickOptions
        {
            FileTypes = FilePickerFileType.Images
        });
        var fullPath = result?.FullPath;
        if (fullPath != null)
        {
            ImageSrc = fullPath;
        }
    }

    [RelayCommand]
    async Task GoBack()
    {
        await Shell.Current.GoToAsync("..");
    }

    [RelayCommand]
    void UpdateRating(double value)
    {
        var tmp = Convert.ToInt32(value);
        Rating = tmp;
    }
}