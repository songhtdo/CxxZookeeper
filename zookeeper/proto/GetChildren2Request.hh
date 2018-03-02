// File generated by hadoop record compiler. Do not edit.

#ifndef GetChildren2Request_HH_
#define GetChildren2Request_HH_

#include "Efc.hh"
#include "../../jute/inc/ERecord.hh"
#include "../../jute/inc/EBinaryInputArchive.hh"
#include "../../jute/inc/EBinaryOutputArchive.hh"
#include "../../jute/inc/ECsvOutputArchive.hh"

namespace efc {
namespace ezk {

class GetChildren2Request: public ERecord {
public:
	EString path;
	boolean watch;

	GetChildren2Request() {
	}
	GetChildren2Request(EString path, boolean watch) {
		this->path = path;
		this->watch = watch;
	}
	EString getPath() {
		return path;
	}
	void setPath(EString m_) {
		path = m_;
	}
	boolean getWatch() {
		return watch;
	}
	void setWatch(boolean m_) {
		watch = m_;
	}
	virtual void serialize(EOutputArchive* a_, const char* tag)
			THROWS(EIOException) {
		a_->startRecord(this, tag);
		a_->writeString(path, "path");
		a_->writeBool(watch, "watch");
		a_->endRecord(this, tag);
	}
	virtual void deserialize(EInputArchive* a_, const char* tag)
			THROWS(EIOException) {
		a_->startRecord(tag);
		path = a_->readString("path");
		watch = a_->readBool("watch");
		a_->endRecord(tag);
	}
	virtual EString toString() {
		try {
			EByteArrayOutputStream s;
			ECsvOutputArchive a_(&s);
			a_.startRecord(this, "");
			a_.writeString(path, "path");
			a_.writeBool(watch, "watch");
			a_.endRecord(this, "");
			s.write('\0');
			return (char*) s.data();
		} catch (EThrowable& ex) {
			ex.printStackTrace();
		}
		return "ERROR";
	}
	void write(EDataOutput* out) THROWS(EIOException) {
		EBinaryOutputArchive archive(out);
		serialize(&archive, "");
	}
	void readFields(EDataInput* in) THROWS(EIOException) {
		EBinaryInputArchive archive(in);
		deserialize(&archive, "");
	}
	virtual int compareTo(EObject* peer_) THROWS(EClassCastException) {
		GetChildren2Request* peer = dynamic_cast<GetChildren2Request*>(peer_);
		if (!peer) {
			throw EClassCastException(__FILE__, __LINE__,
					"Comparing different types of records.");
		}
		int ret = 0;
		ret = path.compareTo(&peer->path);
		if (ret != 0)
			return ret;
		ret = (watch == peer->watch) ? 0 : (watch ? 1 : -1);
		if (ret != 0)
			return ret;
		return ret;
	}
	virtual boolean equals(EObject* peer_) {
		GetChildren2Request* peer = dynamic_cast<GetChildren2Request*>(peer_);
		if (!peer) {
			return false;
		}
		if (peer_ == this) {
			return true;
		}
		boolean ret = false;
		ret = path.equals(&peer->path);
		if (!ret)
			return ret;
		ret = (watch == peer->watch);
		if (!ret)
			return ret;
		return ret;
	}
	virtual int hashCode() {
		int result = 17;
		int ret;
		ret = path.hashCode();
		result = 37 * result + ret;
		ret = (watch) ? 0 : 1;
		result = 37 * result + ret;
		return result;
	}
	static EString signature() {
		return "LGetChildren2Request(sz)";
	}
};

} /* namespace ezk */
} /* namespace efc */
#endif /* GetChildren2Request_HH_ */