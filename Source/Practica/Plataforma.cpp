#include "Plataforma.h"

// Establece los valores predeterminados
APlataforma::APlataforma()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshPlataforma"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Architecture/Wall_Door_400x400.Wall_Door_400x400'"));
	if (MeshAsset.Succeeded()) MeshPlataforma->SetStaticMesh(MeshAsset.Object);
	SetRootComponent(MeshPlataforma);
}

// Llamado cuando el juego inicia o cuando es generado (spawned)
void APlataforma::BeginPlay()
{
	Super::BeginPlay();

	LocacionInicial = GetActorLocation();
}

// Llamado en cada frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoverPlataforma(DeltaTime);
	RotarPlataforma(DeltaTime);
}

void APlataforma::MoverPlataforma(float DeltaTime)
{
	DistanciaMovida = GetDistanciaMovida();

	if (DistanciaMovida >= DistanciaMover)
	{
		float Exceso = DistanciaMovida - DistanciaMover;
		FString NombrePlataforma = GetName();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s se pasó por %f"), *NombrePlataforma, Exceso));

		FVector DireccionMovimiento = VelocidadPlataforma.GetSafeNormal();
		FVector NuevaLocacionInicial = LocacionInicial + DireccionMovimiento * DistanciaMover;
		SetActorLocation(NuevaLocacionInicial);
		LocacionInicial = NuevaLocacionInicial;

		VelocidadPlataforma = -VelocidadPlataforma;
	}
	else
	{
		FVector LocacionActual = GetActorLocation();

		LocacionActual = LocacionActual + (VelocidadPlataforma * DeltaTime);

		SetActorLocation(LocacionActual);
	}
}

void APlataforma::RotarPlataforma(float DeltaTime)
{
	FRotator RotacionAAgregar = VelocidadRotacion * DeltaTime;
	AddActorLocalRotation(RotacionAAgregar);
}

void APlataforma::mensaje()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("clase base APlataforma haciendo su movimiento"));
}
