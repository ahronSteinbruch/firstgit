#include "namespaceGames.h"
#include <stdio.h>

namespace ns1
{
	void doSomething()
	{
		printf("ns1");
	}
}

namespace ns2
{
	void doSomething()
	{
		printf("ns2");
	}
}

namespace outer {
	
	void doSomething()
	{
		printf("outer");
	}

	namespace inner {
		void doSomething()
		{
			printf("outer::inner");
		}
	}
}

namespace very_very_long_namespace_name {
	void doSomething()
	{
		printf("very_very_long_namespace_name");
	}


	namespace inner {
		void doSomething()
		{
			printf("very_very_long_namespace_name::inner");
		}
	}
}