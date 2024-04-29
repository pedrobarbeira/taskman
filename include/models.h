#ifndef _MODELS_H
#define _MODELS_H

struct TableData{
	int instanceId;

	virtual ~TableData(){};
}

struct TaskData : public TableData{
	~TaskData(){};
}

struct ProjectData : public TableData{
	std::string name;
	std::string course;

	~ProjectData(){};
}

#endif //_MODELS_H_
