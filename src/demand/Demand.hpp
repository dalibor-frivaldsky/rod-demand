#pragma once


#include <functional>
#include <utility>

#include <rod/annotation/Component.hpp>

#include <demand/DemandHolder.hpp>




namespace demand
{

	template< typename DemandedType >
	struct Demand
	{
		using Component = rod::annotation::Component;
		using Type = Demand< DemandedType >;
		using Holder = DemandHolder< Type >;

		using SupplyOp = std::function< DemandedType() >;


	private:
		SupplyOp	supplyOp;


	public:
		Demand()
		{}

		Demand( Demand&& other ):
		  supplyOp( std::move( other.supplyOp ) )
		{}

		Demand( const Demand& ) = delete;


		void
		setSupplyOp( SupplyOp supplyOp )
		{
			this->supplyOp = std::move( supplyOp );
		}

		void
		resetSupplyOp()
		{
			this->supplyOp = SupplyOp();
		}


		bool
		hasSuppliers() const
		{
			return (bool) supplyOp;
		}

		DemandedType
		demand()
		{
			return supplyOp();
		}
	};
	
}