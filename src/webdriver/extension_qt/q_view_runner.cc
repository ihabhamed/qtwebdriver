#include "extension_qt/q_view_runner.h"

#include <QtGui/QApplication>

#include "base/synchronization/waitable_event.h"

namespace webdriver {

QViewRunner::QViewRunner()
	: ViewRunner() {
	qt_ui_task.moveToThread(QApplication::instance()->thread());
}

void QViewRunner::RunClosure(const base::Closure& task,
                            base::WaitableEvent* done_event) {
	QMetaObject::invokeMethod(&qt_ui_task, "runTask", Qt::BlockingQueuedConnection, Q_ARG(const base::Closure&, task));
    done_event->Signal();
}

} // namespace webdriver