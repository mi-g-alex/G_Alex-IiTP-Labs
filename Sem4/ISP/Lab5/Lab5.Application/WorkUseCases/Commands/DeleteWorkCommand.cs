namespace Lab5.Application.WorkUseCases.Commands;

public sealed record DeleteWorkCommand(Work Work) : IRequest;