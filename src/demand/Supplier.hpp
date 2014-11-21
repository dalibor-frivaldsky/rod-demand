#pragma once


#include <utility>

#include <demand/Demand.hpp>




namespace demand
{

	template< typename DemandedType >
	class Supplier
	{
		private:
			Demand< DemandedType >&		demand;
			bool						provided = false;


		public:

			Supplier( Demand< DemandedType >& demand ):
			  demand( demand )
			{}

			Supplier( Supplier< DemandedType >&& other ):
			  demand( other.demand ),
			  provided( other.provided )
			{
				other.provided = false;
			}

			Supplier( const Supplier< DemandedType >& ) = delete;

			~Supplier()
			{
				if( provided )
				{
					demand.resetSupplyOp();
				}
			}


			void
			supplyWith( typename Demand< DemandedType >::SupplyOp supplyOp )
			{
				demand.setSupplyOp( std::move( supplyOp ) );
			}
	};
	
}