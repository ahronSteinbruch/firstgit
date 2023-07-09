#pragma once

namespace ns1
{
	void doSomething();
}

namespace ns2
{
	void doSomething();
}

namespace outer {
	
	void doSomething();

	namespace inner {
		void doSomething();
	}
}

namespace very_very_long_namespace_name {
	void doSomething();

	namespace inner {
		void doSomething();
	}
}