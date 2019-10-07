#pragma once
#ifndef NUKEE_ID_H
#define NUKEE_ID_H

class NUKEENGINE_API ID {
public:
    long id;

	ID();
	ID(long id);

	void generate();
};
#endif // !NUKEE_ID_H
