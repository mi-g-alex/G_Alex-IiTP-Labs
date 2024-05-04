namespace Lab5.Application.BrigadeUseCases.Commands;

public interface IAddOrEditBrigadeRequest : IRequest
{
    Brigade Brigade { get; set; }
}