#ifndef XMLLOGGER_H
#define	XMLLOGGER_H
#include "tinyxml2.h"
#include "ilogger.h"

class XmlLogger : public ILogger {

public:
    XmlLogger(std::string loglevel):ILogger(loglevel){}

    virtual ~XmlLogger() {};

    bool getLog(const char *FileName, const std::string *LogParams);

    void saveLog();

    void writeToLogMap(const Map &Map, const std::list<ANode> &path);

    void writeToLogOpenClose(const std::vector<std::list<ANode>> &open, const std::unordered_map<int, ANode> &close, bool last);

    void writeToLogPath(const std::list<ANode> &path);

    void writeToLogHPpath(const std::list<ANode> &hppath);

    void writeToLogNotFound();

    void writeToLogSummary(unsigned int numberofsteps, unsigned int nodescreated, float length, double time, double cellSize, float alength, bool acorrect);

private:
    std::string LogFileName;
    tinyxml2::XMLDocument doc;
};

#endif
