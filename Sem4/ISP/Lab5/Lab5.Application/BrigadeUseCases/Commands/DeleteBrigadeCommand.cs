namespace Lab5.Application.BrigadeUseCases.Commands;

public sealed record DeleteBrigadeCommand(Brigade Brigade) : IRequest;