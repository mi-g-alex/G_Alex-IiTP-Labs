namespace Lab5.Application.BrigadeUseCases.Queries;

internal class GetBrigadesQueryHandler(IUnitOfWork unitOfWork) : IRequestHandler<GetBrigadesQuery, IEnumerable<Brigade>>
{

    public async Task<IEnumerable<Brigade>> Handle(GetBrigadesQuery request, CancellationToken cancellationToken)
    {
        return await unitOfWork.BrigadeRepository.ListAllAsync(cancellationToken);
    }
}