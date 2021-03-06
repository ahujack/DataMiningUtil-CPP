/*
 * conf_util.h
 *
 *  Created on: 2013-8-24
 *      Author: Yan Shankai
 */

#ifndef CONF_UTIL_H_
#define CONF_UTIL_H_

#include <map>

using namespace std;

class ConfInstance {
public:
	ConfInstance(const char* identifier, const char* conf_path);
	virtual ~ConfInstance();
	const char* get_configuration(const char* conf_name);

private:
	const char* m_identifier;
	map<char*, char*> m_configuration;
};

class ConfUtil {
public:
	virtual ~ConfUtil();
	static ConfUtil* get_instance();
	static void destroy_instance();
	ConfInstance* get_conf_instance(const char* identifier);

private:
	ConfUtil();

private:
	static ConfUtil* m_instance;
	map<const char*, ConfInstance*> m_conf_instances;

	class __Garbage__ {
	public:
		~__Garbage__() {
			ConfUtil::destroy_instance();
		}
	};
	static __Garbage__ m_garbage;
};

#endif /* CONF_UTIL_H_ */
