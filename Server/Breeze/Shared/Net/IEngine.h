/*
    Copyright (c) 2007-2011 iMatix Corporation
    Copyright (c) 2007-2011 Other contributors as noted in the AUTHORS file

    This file is part of 0MQ.

    0MQ is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    0MQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __SHARED_NET_IENGINE_H__
#define __SHARED_NET_IENGINE_H__

namespace FREEZE_NET
{

    struct IEngine
    {
        virtual ~IEngine(){}

        //  Plug the engine to the session.
        virtual void Plug(class IOThread *io_thread_) = 0;

        //  Unplug the engine from the session.
        virtual void Unplug() = 0;

        //  Terminate and deallocate the engine. Note that 'detached'
        //  events are not fired on termination.
        virtual void Terminate() = 0;

        //  This method is called by the session to signalise that more
        //  messages can be written to the pipe.
        virtual void ActivateIn() = 0;

        //  This method is called by the session to signalise that there
        //  are messages to send available.
        virtual void ActivateOut() = 0;
    };

}

#endif