namespace Lab5.Application.WorkUseCases.Queries;

public sealed record GetWorkByIdQuery(int Id) : IRequest<Work>;