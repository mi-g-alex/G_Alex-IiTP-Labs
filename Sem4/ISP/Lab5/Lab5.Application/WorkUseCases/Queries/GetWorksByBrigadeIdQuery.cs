namespace Lab5.Application.WorkUseCases.Queries;

public sealed record GetWorksByBrigadeIdQuery(int Id) : IRequest<IEnumerable<Work>>;