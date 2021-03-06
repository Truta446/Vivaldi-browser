// VIVALDI

var GuestViewAttributes = require('guestViewAttributes').GuestViewAttributes;
var WebViewConstants = require('webViewConstants').WebViewConstants;

function TabIdAttribute(view) {
  GuestViewAttributes.Attribute.call(this,
    WebViewConstants.ATTRIBUTE_TAB_ID, view);
}

TabIdAttribute.prototype.__proto__ =
  GuestViewAttributes.Attribute.prototype;

TabIdAttribute.prototype.handleMutation = function (oldValue, newValue) {
  // nothing to do here
};

function InspectTabIdAttribute(view) {
  GuestViewAttributes.Attribute.call(this,
    WebViewConstants.ATTRIBUTE_INSPECT_TAB_ID, view);
}

InspectTabIdAttribute.prototype.__proto__ =
  GuestViewAttributes.Attribute.prototype;

InspectTabIdAttribute.prototype.handleMutation = function (oldValue, newValue) {
  // nothing to do here
};

function WasTypedAttribute(view) {
  GuestViewAttributes.BooleanAttribute.call(this,
     WebViewConstants.ATTRIBUTE_WASTYPED, view);
  this.wasTyped = true;
}

WasTypedAttribute.prototype.__proto__ =
  GuestViewAttributes.BooleanAttribute.prototype;

WasTypedAttribute.prototype.handleMutation = function (oldValue, newValue) {
  if (!newValue && oldValue) {
    this.wasTyped = (newValue === 'true');
    this.setValueIgnoreMutation(newValue);
  }
};

function addVivaldiWebViewAttributes(athis) {
  athis.InspectTabIdAttribute = InspectTabIdAttribute;
  athis.TabIdAttribute = TabIdAttribute;
  athis.WasTypedAttribute = WasTypedAttribute;
}
// Exports.
exports.$set('addVivaldiWebViewAttributes', addVivaldiWebViewAttributes);
