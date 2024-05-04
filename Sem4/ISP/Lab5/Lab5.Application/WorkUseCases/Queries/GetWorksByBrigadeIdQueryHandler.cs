namespace Lab5.Application.WorkUseCases.Queries;

internal class GetWorksByBrigadeIdQueryHandler(IUnitOfWork unitOfWork)
    : IRequestHandler<GetWorksByBrigadeIdQuery, IEnumerable<Work>>
{
    public async Task<IEnumerable<Work>> Handle(GetWorksByBrigadeIdQuery request, CancellationToken cancellationToken)
    {
        var a = await unitOfWork.WorkRepository.ListAsync(s => s.BrigadeId.Equals(request.Id), cancellationToken);
        return a.Where(s => s.BrigadeId == request.Id);
    }
}