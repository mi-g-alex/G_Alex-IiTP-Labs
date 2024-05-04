namespace Lab5.Application.BrigadeUseCases.Commands;

public sealed class AddBrigadeCommand: IAddOrEditBrigadeRequest
{
    public Brigade Brigade { get; set; }
}