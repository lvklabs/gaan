#ifndef EASYTRACKER_H
#define EASYTRACKER_H

#include <string>

namespace gaan
{

/**
 * @brief The EasyTracker class
 */
class EasyTracker
{
public:
    static void sendEvent(const std::string &category,
                          const std::string &action,
                          const std::string &label,
                          long value);
};

} // namespace GoogleAnalytics

#endif // EASYTRACKER_H
