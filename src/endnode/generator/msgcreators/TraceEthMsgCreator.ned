//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package idaTSNSimulator.endnode.generator.msgcreators;

//
// This module creates and forwards a raw Ethernet message upon stimulation from a source module
//
simple TraceEthMsgCreator
{
    parameters:
        bool enableFineGrainedLatencyStats;
    gates:
        /// The port to receive trigger messages from the generator source.
        input fromSrc; 
        /// The output port to the UDP/IP Stack
        output toStack;
}
