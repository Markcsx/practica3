/*
 * jornada.cpp
 *
 */

#include "jornada.h"
#include "partit.h"


CJornada::CJornada() {
	// Defineix aquí el constructor per defecte
	// Ha d'inicialitzar:
	//	- el numero de jornada al valor zero
	//	- la data d'inici de la jornada al 1 de gener del 2000
	//	- la quantitat d'àlbums al valor zero
	//	- l'apuntador de l'array dinàmic apuntant a l'adreça 0.
	m_numJornada = 0;
	m_data.SetData(1,1,2000);
	m_partitsjornada = 0;
	m_objectes = 0;
}

CJornada::~CJornada() {
	// Defineix aquí el destructor
	// Ha d'alliberar la memòria dinàmica que es pugui tenir reservada
	delete [] m_objectes;
};

istream& operator>> (istream &is, CJornada& jornadas)
	{
		//delete[] jornadas.m_objectes;
		is >> jornadas.m_numJornada;
		is >> jornadas.m_data;
		is >> jornadas.m_partitsjornada;
		jornadas.m_objectes= new CPartit [jornadas.m_partitsjornada];//assigna memoria dinamica
		for (int i=0 ; i<jornadas.m_partitsjornada; i++)//contador de los array
		{
			is >> jornadas.m_objectes[i];
		}
		return is;
	}
ostream& operator<< (ostream &os, const CJornada& jornadas)
	{
		os << "Jornada ";
		os << jornadas.m_numJornada << " ";
		os << jornadas.m_data << " " << endl;
		for (int i=0 ; i<jornadas.m_partitsjornada; i++)
		{
			os << jornadas.m_objectes[i] << endl;
		}
		return os;
	}

bool
CJornada::PartitMajorDiferenciaGols(CPartit& partit)
{
	bool retValor=false;
	if(m_partitsjornada==0)
	{
		 retValor=false;
	} else
	{
		int total=m_objectes[0].GolsTotal();
		for(int i=0;i<m_partitsjornada;i++)
		{
				if(total<m_objectes[i].GolsTotal())
				{
					total=m_objectes[i].GolsTotal();
					partit=m_objectes[i];
				}
		}
		retValor=true;
	}
	return retValor;
}

void
CJornada::MostraVictoriesLocals(ostream& os)
{

	for(int i=0;i<m_partitsjornada;i++)
	{
		int locales=m_objectes[i].GetGolsLocal();
		int visitantes=m_objectes[i].GetGolsVisitant();
		if(locales>visitantes)
		{
			os<<m_objectes[i]<< endl;
		}
	}
}


int
CJornada::GetNumJornada()
{
	return m_numJornada;

	/*
	int NumJornada = 0;
	for (int i=0; i<m_partitsjornada;i++){
		if(m_objectes[0].GolsTotal()<m_objectes[i].GolsTotal())
		{
			NumJornada =m_objectes[i].GolsTotal();
		}
	}
	return NumJornada;
	*/

}


