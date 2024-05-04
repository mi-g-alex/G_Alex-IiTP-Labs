namespace Lab5.Application.WorkUseCases.Commands;

public interface IAddOrEditWorkRequest : IRequest
{
    Work Work { get; set; }
}